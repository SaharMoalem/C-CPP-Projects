# Compile DHCP:
gd ../test/test_dhcp.c ../src/dhcp.c ../../../ds/src/trie.c ../../../ds/src/bit_array.c -I ../include/ -I ../../../ds/include/ -o dhcp