sudo apt update
sudo apt install -y cmake ninja-build

cd ~/Coding/MatMul
git clone --recursive https://github.com/google/XNNPACK.git
cd XNNPACK
mkdir build && cd build
cmake -G Ninja .. -DXNNPACK_ENABLE_ARM_FP16=ON -DXNNPACK_ENABLE_BF16=ON
ninja
