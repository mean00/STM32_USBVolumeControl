SET(COMPOSITE_SRC USBComposite/MinSysex.c
USBComposite/usb_audio.c
USBComposite/usb_composite_serial.c
USBComposite/usb_generic.c
USBComposite/usb_hid.c
USBComposite/usb_mass.c
USBComposite/usb_mass_mal.c
USBComposite/usb_midi_device.c
USBComposite/usb_multi_serial.c
USBComposite/usb_multi_x360.c
USBComposite/usb_scsi.c
USBComposite/usb_scsi_data.c
USBComposite/usb_x360_generic.c
USBComposite/usb_x360w.c)

include_directories(USBComposite)
generate_arduino_library(${libPrefix}HID 
                            SRCS ${COMPOSITE_SRC}
                            BOARD ${ARDUINO_DEFAULT_BOARD}
                        )

                           
                            
                            

