add_library(drawbot SHARED ../drawbot.h ../drawbot.cpp ../stepper.h ../serial.h ../protocol.h stepper_stub.h serial_stub.h protocol_stub.h stepper_stub.cpp serial_stub.cpp protocol_stub.cpp)
