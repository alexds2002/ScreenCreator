# ScreenCreator

# Requirments
cmake 3.16
make 4.2.1

# How to build and run(Linux) manually
Create a build directory, run cmake and then make:
mkdir build && cmake -G "Unix Makefiles" .. && make -j4 && ./ScreenCreator
Note: on Windows it would be something like                ./ScreenCreator.exe

# Or run build_and_run.py scrpipt from the project root directory
python3 build_and_run.py
