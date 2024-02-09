# Python code transmits a byte to Arduino /Microcontroller
import serial
import cv2
from HandTrackingModule import FindHands

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1080)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)

detector = FindHands()

SerialObj = serial.Serial('COM17') # COMxx  format on Windows
                  # ttyUSBx format on Linux
SerialObj.baudrate = 9600  # set Baud rate to 9600
SerialObj.bytesize = 8   # Number of data bits = 8
SerialObj.parity  ='N'   # No parity
SerialObj.stopbits = 1   # Number of Stop bits = 1A
# time.sleep(3)
print("Press W or S")
while True:
    succeed, img = cap.read()
    hand1_positions = detector.getPosition(img, range(21), draw=False)
    # hand2_positions = detector.getPosition(img, range(21), hand_no=1, draw=False)
    for pos in hand1_positions:
        cv2.circle(img, pos, 5, (0,255,0), cv2.FILLED)
    # for pos in hand2_positions:
    #     cv2.circle(img, pos, 5, (255,0,0), cv2.FILLED)

    font = cv2.FONT_HERSHEY_COMPLEX
    hand = "None"

    if(detector.index_finger_up(img) != "NO HAND FOUND" and detector.index_finger_up(img) != False
       and detector.middle_finger_up(img) != "NO HAND FOUND" and detector.middle_finger_up(img) != False
        and  detector.ring_finger_up(img) != "NO HAND FOUND" and detector.ring_finger_up(img) != False 
        and detector.little_finger_up(img) != "NO HAND FOUND" and detector.little_finger_up(img) != False ):
        hand = "All fingers up"
        SerialObj.write(b'W') 

    elif(detector.index_finger_up(img) != "NO HAND FOUND" and detector.index_finger_up(img) != False):
        hand = "Index finger"
        SerialObj.write(b'S') 
    elif(detector.middle_finger_up(img) != "NO HAND FOUND" and detector.middle_finger_up(img) != False):
        hand = "Middle finger"
        SerialObj.write(b'D')
    # elif(detector.ring_finger_up(img) != "NO HAND FOUND" and detector.ring_finger_up(img) != False):
    #     hand = "Ring finger up"
    #     SerialObj.write(b'A') 

    elif(detector.little_finger_up(img) != "NO HAND FOUND" and detector.little_finger_up(img) != False):
        hand = "Little finger"
        SerialObj.write(b'A')
    
    # elif(detector.ring_finger_up(img)):
    #     hand = "Ring finger"
    #     SerialObj.write(b'A')
    else:
        hand = "No finger found"
        SerialObj.write(b'Q') 


    cv2.putText(img,  
            hand,  
            (50, 50),  
            font, 1,  
            (255, 0, 0),  
            2,  
            cv2.LINE_4) 
    
    cv2.imshow("Image", img)
    if cv2.waitKey(10) == ord('q'):
        break

    # if(keyboard.is_pressed("w")):
    #     SerialObj.write(b'W')   #transmit 'A' (8bit) to micro/Arduino
    # elif(keyboard.is_pressed("s")):
    #     SerialObj.write(b'S')
    # elif(keyboard.is_pressed("a")):
    #     SerialObj.write(b'A')
    # elif(keyboard.is_pressed("d")):
    #     SerialObj.write(b'D')
    
    # else:
    #     SerialObj.write(b'Q') 
    
SerialObj.close()  