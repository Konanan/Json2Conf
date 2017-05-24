desDir=$1
echo $desDir
cd $desDir
ls
lipo -create Release-iphonesimulator/libquickcocos2dx.a Release-iphoneos/libquickcocos2dx.a -output libquickcocos2dx.a