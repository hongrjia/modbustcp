import os
import re
import json
import copy

directory_path = "./file"
file_list = os.listdir(directory_path)

pattern = re.compile(r'extern (\w+)\s+(\w+)\(([^)]*)\);(?:[^{]*\{([^}]*)\})?')
parm_pattern = re.compile(r'(\w+\*?)\s+(\w+)(?:,|$)')

for file_name in file_list:
    file_path = os.path.join(directory_path, file_name)
    print(f"文件名: {file_name}")
    print(f"完整路径: {file_path}")
    signals = {}

    with open(file_path, "r", encoding='utf-8') as file:
        file_content = file.read()
        matches = pattern.findall(file_content)

        for match in matches:
            return_type, function_name, parameters, comment_block = match
            parm_matches = parm_pattern.findall(parameters)

            if len(parm_matches) < 2:
                continue

            func = []
            if "*" in parm_matches[1][0]:
                func = function_name.split("_get_")
                if func[-1] not in signals:
                    signals[func[-1]] = {}
                signals[func[-1]]["name"] = copy.deepcopy(func[-1])
                signals[func[-1]]["get"] = copy.deepcopy(function_name)

                if len(parm_matches) == 2:
                    if "int" in parm_matches[1][0]:
                        signals[func[-1]]["type"] = copy.deepcopy("int")
                    else:
                        signals[func[-1]]["type"] = copy.deepcopy("float")
                elif len(parm_matches) == 3:
                    if "int" in parm_matches[1][0]:
                        signals[func[-1]]["type"] = copy.deepcopy("int_int")
                    else:
                        signals[func[-1]]["type"] = copy.deepcopy("float_int")
            else:
                func = function_name.split("_set_")
                if func[-1] not in signals:
                    signals[func[-1]] = {}
                signals[func[-1]]["name"] = copy.deepcopy(func[-1])
                signals[func[-1]]["set"] = copy.deepcopy(function_name)

        print("\n" + "="*30 + "\n")
        # print(signals)
        jso = []
        for i in signals:
            print(signals[i])
            jso.append(signals[i])
        # 保存为 JSON 文件
        with open(file_name + ".json", "w", encoding='utf-8') as dumpfile:
            json.dump(jso, dumpfile, indent=4, ensure_ascii=False)

input("exit")
