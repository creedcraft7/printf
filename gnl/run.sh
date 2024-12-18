#!/bin/bash

sed -i '/BUFFER_SIZE/ { /^[^/]/ s|^|// | }' get_next_line.h
cd gnlTester/ && make m && cd ..
sed -i '/BUFFER_SIZE/ s|^// ||' get_next_line.h
