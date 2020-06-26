cd mcu
./make.sh  "BIRD_A_P0MP2_K37MV1_BSP(LWG_DSDS_COTSX).mak" new
cd ..
perl ./mcu/modemRenameCopy.pl ./mcu "BIRD_A_P0MP2_K37MV1_BSP(LWG_DSDS_COTSX)"
mv ./mcu/temp_modem ./zte_blade_a476

cd apps
./build.sh clean,build,pack all GEN90_USER
cd ..
tar -C ./zte_blade_a476 -xvjf ./apps/GEN90_USER_rel.tar.bz2 --strip-components 1
#cp ./apps/GEN90_USER_rel.tar.bz2 ./modem_p0/
