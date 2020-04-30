cd mcu
./make.sh  "BIRD_A_P0MP2_K37MV1_BSP(LWG_DSDS_COTSX).mak" new
cd ..
perl ./mcu/modemRenameCopy.pl ./mcu "BIRD_A_P0MP2_K37MV1_BSP(LWG_DSDS_COTSX)"
mv ./mcu/temp_modem ./modem_p0

cd apps
./build.sh clean,build,pack all GEN90_USER
cd ..
cp ./apps/GEN90_USER_rel.tar.bz2 ./modem_p0/
