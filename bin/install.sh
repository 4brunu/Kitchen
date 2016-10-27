PROJECT_NAME='naomi'
OBJC_DEPENDENCIES=''
ANDROID_DEPENDENCIES=''
GYP=lib$PROJECT_NAME.gyp;

while [[ $# > 1 ]]
do
	key="$1"
	case $key in -p|--project_root)
		PROJECT_ROOT="$2"
		shift ;;
	-i|--import)
		find_="."
		replace_="/"
		IMPORT=$2
		IMPORT_PACKAGE=$(echo $IMPORT | sed 's/\./\//g')
		shift;;
	-f|--prefix)
		PREFIX=$2
		shift;;
	-a|--module)
		PROJECT_MODULE=$2
		shift;;
	esac
	shift
done

cp .Makefile Makefile
cp .run_djinni.sh run_djinni.sh
cp .$GYP $GYP

PROJECT_MODULE=$(echo ${PROJECT_MODULE,,})

sed -i -e "s/{IMPORT}/$IMPORT/g" run_djinni.sh
sed -i -e "s@{IMPORT_PACKAGE}@$IMPORT_PACKAGE@g" run_djinni.sh
sed -i -e "s/{PREFIX}/$PREFIX/g" run_djinni.sh
sed -i -e "s/{PROJECT_NAME}/$PROJECT_NAME/g" run_djinni.sh
sed -i -e "s/{PROJECT_NAME}/$PROJECT_NAME/g" Makefile
sed -i -e "s/{PROJECT_ROOT}/$PROJECT_ROOT/g" Makefile
sed -i -e "s/{PROJECT_MODULE}/$PROJECT_MODULE/g" Makefile

IN=$(cat ../djinni.conf)
set -- "$IN" 
IFS=";"; declare -a Array=($*)

for module in $*;
do
	module="${module#"${module%%[![:space:]]*}"}"
	module="${module%"${module##*[![:space:]]}"}"

	module="${module#"\""}"
	module="${module%"\""}"

	OBJC_DEPENDENCIES="$OBJC_DEPENDENCIES\"../../$module/$module.gyp:lib${module}_objc\", \r\n\t      "
	ANDROID_DEPENDENCIES="$ANDROID_DEPENDENCIES\"../../$module/$module.gyp:lib${module}_jni\", \r\n\t      "
	echo "@import \"../../$module/$module.djinni\"" >> $PROJECT_NAME.djinni
done 

sed -i -e "s/{PROJECT_NAME}/$PROJECT_NAME/g" $GYP
sed -i -e "s@{OBJC_DEPENDENCIES}@$OBJC_DEPENDENCIES@g" $GYP
sed -i -e "s@{ANDROID_DEPENDENCIES}@$ANDROID_DEPENDENCIES@g" $GYP

cp glob.py ../core/$PROJECT_NAME
mv Makefile ../core/Makefile
mv run_djinni.sh ../core/$PROJECT_NAME/run_djinni.sh
mv $PROJECT_NAME.djinni ../core/$PROJECT_NAME/$PROJECT_NAME.djinni
mv $GYP ../core/$PROJECT_NAME/$GYP

pushd ../core
make android
popd

