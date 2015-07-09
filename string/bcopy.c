/* bcopy -- copy memory regions of arbitary length
 *
 *  NAME
 *   bcopy -- copy memory regions of arbitrary length
 *
 * SYNOPSIS
 *	void bcopy (char *in, char *out, int length)
 *
 * DESCRIPTION
 *	Copy LENGTH bytes from memory region pointed to by IN to memory
 *	region pointed to by OUT.
 * 
 *  BUGS
 *	Significant speed improvements can be made in some cases by
 *	implementing copies of multiple bytes simultaneously, or unrolling
 *	the copy loop.
 *
 */

void bcopy(register char *src, register char *dest, int len) {
    
    if(dest < src) {
        while(len--) {
            *dest++ = *src++;
        }
    } else {
        char *last_src = src + (len - 1);
        char *last_dest = dest + (len - 1);
        while(len--) {
            *(char *)last_dest-- = *(char *)last_src--;
        }
    }
}