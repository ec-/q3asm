/* 
	copied from qfiles.h, should be synced with host qvm format
	- made for standalone compilation
*/

#define	VM_MAGIC        0x12721444
#define	VM_MAGIC_VER2   0x12721445

typedef struct {
	int		vmMagic;

	int		instructionCount;

	int		codeOffset;
	int		codeLength;

	int		dataOffset;
	int		dataLength;
	int		litLength;			// ( dataLength - litLength ) should be byteswapped on load
	int		bssLength;			// zero filled memory appended to datalength

	//!!! below here is VM_MAGIC_VER2 !!!
	int		jtrgLength;			// number of jump table targets
} vmHeader_t;


typedef enum {
	CODESEG,
	DATASEG,	// initialized 32 bit data, will be byte swapped
	LITSEG,		// strings
	BSSSEG,		// 0 filled
	JTRGSEG,	// psuedo-segment that contains only jump table targets
	NUM_SEGMENTS
} segmentName_t;
