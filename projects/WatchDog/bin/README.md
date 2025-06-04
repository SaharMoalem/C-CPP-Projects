# Compile WatchDog:

# create .so:
gd -fPIC ../src/inner_watchdog.c ../src/watchdog.c -shared -I ../include -I ../../../ds/include -Wl,-rpath=debug -L debug -o debug/libinner_watchdog.so

# create wd.out:
gd ../src/inner_watchdog_main.c ../src/logger.c -Ldebug -linner_watchdog -Wl,-rpath=debug -I../include 
-I ../../../ds/include -o debug/wd.out -lheap_scheduler

# create user.out:
gd ../test/test_wd.c ../src/logger.c -Ldebug -linner_watchdog -Wl,-rpath=debug -I../include -I ../../../ds/include -o debug/user.out -lheap_scheduler