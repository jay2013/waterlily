# clean files in src_login/
dir="src"
rm ${dir}/Makefile ${dir}/CMakeCache.txt $dir/cmake_install.cmake 
rm -rf $dir/CMakeFiles/
rm -rf $dir/debug/
rm $dir/test.e

rm -rf $dir/tests/CMakeFiles/
rm $dir/tests/libtest.a $dir/tests/cmake_install.cmake $dir/tests/Makefile

# clean files in src_login/event
 rm -rf $dir/utils/CMakeFiles/
 rm $dir/utils/libutils.a $dir/utils/cmake_install.cmake $dir/utils/Makefile

# clean files in src_login/common
#rm -rf $dir/common/CMakeFiles/
#rm $dir/common/libcommon.a $dir/common/cmake_install.cmake $dir/common/Makefile

# clean files in src_login/class
rm -rf $dir/class/CMakeFiles/
rm $dir/class/libclass.a $dir/class/cmake_install.cmake $dir/class/Makefile

#clean files in src_login/net
rm -rf $dir/net/CMakeFiles/
rm $dir/net/libnet.a $dir/net/cmake_install.cmake $dir/net/Makefile

#clean files in src_login/utils
rm -rf $dir/cfg/CMakeFiles/
rm $dir/cfg/libcfg.a $dir/cfg/cmake_install.cmake $dir/cfg/Makefile

