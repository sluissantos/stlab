sudo apt update
sudo apt install cmake libssl-dev
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
cmake -Bbuild -H. -DPAHO_BUILD_STATIC=TRUE -DPAHO_BUILD_DOCUMENTATION=FALSE
cmake --build build/ --target install
sudo ldconfig
