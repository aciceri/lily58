#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hidapi/hidapi.h>


int main(int argc, char* argv[]) {
        int res;
        unsigned char buf[33];
        hid_device* handle;
        hid_init();

        struct hid_device_info *devs, *cur_dev;

        devs = hid_enumerate(0x04d8, 0xeb2d);
        cur_dev = devs;
        while (cur_dev) {
                if (cur_dev->interface_number == 1) handle = hid_open_path(cur_dev->path);
                cur_dev = cur_dev->next;
        }
        hid_free_enumeration(devs);


        buf[0] = 0;
	buf[1] = atoi(argv[1]);
	
	for (int i=0; i<21; i++) {
	  buf[i+2] = (i < strlen(argv[2])) ? argv[2][i] : ' ';
	}
	
        res = hid_write(handle, buf, 33);
        printf("%d\n", res);


        hid_close(handle);

        hid_exit();

        return 0;
}
