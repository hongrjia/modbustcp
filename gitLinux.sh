if [ ! -d .git ];then
   echo "not found .git"
   exit 1
fi

OUTDIR=$1
if [ -z $OUTDIR ];then
    if [ -d sdk/src ];then
        OUTDIR="sdk/include"
    else
        OUTDIR="include"
    fi
fi

FILE_H=${OUTDIR}/gitver.h

GIT_SHA1=$(git rev-parse HEAD)
GIT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
GIT_REMOTE_SHA1=$(git rev-parse origin/${GIT_BRANCH})
GIT_REMOTE=$(git ls-remote --get-url origin)
GIT_DATE=$(git log -1 --format=%ad --date=local)
COMMIT_NUM=$(git rev-list origin/master | wc -l)
MODIFY_NUM=$(git status | grep "modified:" | wc -l)
USERNAME=$(whoami)

echo "COMMIT_NUM=$COMMIT_NUM"

if [ "_$GIT_SHA1" = "_$GIT_REMOTE_SHA1" ];then
    GIT_VER="R"
else
    GIT_VER=$(whoami)\#
fi

GIT_VER=${GIT_VER}${COMMIT_NUM}
echo "GIT_VER1=$GIT_VER"

if [ $MODIFY_NUM -ne  0 ];then
    GIT_VER=${GIT_VER}M${MODIFY_NUM}
    echo "GIT_VER2=$GIT_VER"
fi

echo "FILE_H=$FILE_H"
echo "GIT_VER=$GIT_VER"

echo "#ifndef __GIT_VER_H" > ${FILE_H}
echo "#define __GIT_VER_H" >> ${FILE_H}

echo "" >>${FILE_H}
echo "#define GIT_VER    \"$GIT_VER\""  >> ${FILE_H}
echo "#define GIT_SHA1   \"$GIT_SHA1\"" >> ${FILE_H}
echo "#define GIT_DATE   \"$GIT_DATE\"" >> ${FILE_H}
echo "#define GIT_BRANCH \"$GIT_BRANCH\"" >> ${FILE_H}
echo "#define GIT_REMOTE \"$GIT_REMOTE\"" >> ${FILE_H}
echo "#define GIT_REMOTE_SHA1   \"$GIT_REMOTE_SHA1\"" >> ${FILE_H}
echo "#define COMPILE_USER      \"$USERNAME\"" >> ${FILE_H}
echo "" >> ${FILE_H}

echo "#endif" >> ${FILE_H}
