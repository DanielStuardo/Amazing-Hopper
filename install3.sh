#!/bin/bash

#hbmk2 -lhbct -lhbmisc -D_LINUX64_ -static  hopper
if [ "$1" == "H" ];then 
   /usr/local/bin/hbmk2 -lhbct -D_LINUX64_ -static  hopper3c
   #hbmk2 -lhbct -lhbmisc -D_LINUX64_ -static  hopper3c
else
 
   if [  "$1" == "B" ];then 
      /usr/local/bin/hbmk2 -ldflag=lm -lhbct -D_LINUX64_ -static  hopper3b
      #hbmk2 -ldflag=lm -lhbct -lhbmisc -D_LINUX64_ -static  hopper3b
   else
      /usr/local/bin/hbmk2 -ldflag=lm -lhbct -D_LINUX64_ -static  hopper3c
      /usr/local/bin/hbmk2 -ldflag=lm -lhbct -D_LINUX64_ -static  hopper3b
#      hbmk2 -ldflag=lm -lhbct -lhbmisc -D_LINUX64_ -static  hopper3c
#      hbmk2 -ldflag=lm -lhbct -lhbmisc -D_LINUX64_ -static  hopper3b
   fi
fi

echo "Installing Hopper language, Amazing Grace!..."
if [ "$1" == "H" ];then 
   sudo cp hopper3c /usr/bin/hopper3
   
else 
   if [  "$1" == "B" ];then 
      sudo cp hopper3b /usr/bin/bhopper3
   else
      sudo cp hopper3c /usr/bin/hopper3
      sudo cp hopper3b /usr/bin/bhopper3
   fi
fi
# aplica permisos (necesario para debian:
sudo chmod 777 /usr/bin/hopper3
sudo chmod 777 /usr/bin/bhopper3

if [ ! -d "/usr/include/hopper" ]; then 
   sudo mkdir /usr/include/hopper
fi

./fcpy.sh

#sudo cp hbasic.h /usr/include/hopper
#sudo cp amazing.grace /usr/include/hopper
#sudo cp stdio.hh /usr/include/hopper
#sudo cp math.hh /usr/include/hopper
#sudo cp term.hh /usr/include/hopper
#sudo cp string.hh /usr/include/hopper
#sudo cp time.hh /usr/include/hopper
#sudo cp file.hh /usr/include/hopper
#sudo cp array.hh /usr/include/hopper
#sudo cp hash.hh /usr/include/hopper
#sudo cp stat.hh /usr/include/hopper
#sudo cp hispania.hh /usr/include/hopper
echo "Install ok!"
exit 0
