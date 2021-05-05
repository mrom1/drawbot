###########################################################################
## This file is part of the minilockcpp distribution 
## (https://github.com/mrom1/minilockcpp).
## Copyright (c) 2021 mrom1.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, version 3.
##
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program. If not, see <http://www.gnu.org/licenses/>.
###########################################################################



###########################################################################
## Build simulation library
###########################################################################
add_library(drawbot SHARED 
    ../drawbot.h ../drawbot.cpp 
    ../stepper.h ../serial.h 
    ../protocol.h 
    stepper_stub.h 
    serial_stub.h 
    protocol_stub.h 
    stepper_stub.cpp 
    serial_stub.cpp 
    protocol_stub.cpp)
