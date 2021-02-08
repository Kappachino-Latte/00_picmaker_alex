#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main () {

	int fd;
	char data [100];
	int x, y, r, g, b;
	
	fd = open ("img.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	char header[] = "P3 500 500 255\n";
	write (fd, header, sizeof(header) - 1);
	
	for (x = 0; x <= 500; x++) {
		for (y = 0; y <= 500; y++) {
			if ((x % 20 <= 5) && (y % 20 <= 2) && (x < 300)) {
				if ((x % 10 <= 2) && (y % 10 <= 1)) {
					r = 0;
					g = 0;
					b = 0;
				}
				else {
					r = 25;
					g = 50;
					b = 200;
				}
				snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                		write(fd, data, strlen(data));
			}
			else if (x > 325) {
				r = 128;
				g = 128;
				b = 128;
				snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                		write(fd, data, strlen(data));
			}
			else {
				r = 0;
				g = 0;
				b = 0;
				snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                		write(fd, data, strlen(data));
			}
		}
	}
	
	close (fd);
	printf ("Made image\n");
	
	return 0;
}
	
