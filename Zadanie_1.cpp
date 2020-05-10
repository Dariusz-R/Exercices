#pragma once

/*

	Class of Circular Buffer. "bufferSizeDatatype" implemented to provide buffer size flexibility - from few element buffers to long long size buffers.
	"bufferIntelDatatype" implementation makes buffer more versitile. It does everything what was described in the exercise description for all numeric
	datatypes and also chars and strings.

*/

template < class bufferSizeDatatype, class bufferIntelDatatype >			
class CircularBuffer														
{																				
	bufferIntelDatatype* buffer;
	bufferSizeDatatype bufferHeadIndex;
	bufferSizeDatatype bufferTailIndex;
	bufferSizeDatatype elementsInBuffer;
	bufferSizeDatatype sizeOfTheBuffer;

public:

	CircularBuffer(bufferSizeDatatype sizeOfTheBuffer, bufferIntelDatatype)
	{
		buffer = new bufferIntelDatatype[sizeOfTheBuffer];
		elementsInBuffer = 0;
		bufferHeadIndex = 0;
		bufferTailIndex = 0;
		this->sizeOfTheBuffer = sizeOfTheBuffer;

	}

	~CircularBuffer() {
		delete[] buffer;
	}

	void clearBuffer() {
		bufferHeadIndex = bufferTailIndex;
		elementsInBuffer = 0;
	}

	void addElementToTheBuffer(bufferIntelDatatype elementToAdd) {

		buffer[bufferHeadIndex] = elementToAdd;

		if (bufferHeadIndex == bufferTailIndex && elementsInBuffer != 0) {
			bufferTailIndex = (bufferTailIndex + 1) % sizeOfTheBuffer;
		}
		else {
			elementsInBuffer++;
		}

		bufferHeadIndex = (bufferHeadIndex + 1) % sizeOfTheBuffer;
	}

	bufferIntelDatatype getElementFromTheBuffer() {
		
		try {
			if (elementsInBuffer == 0) {
				throw 1;
			}
			else {
				bufferTailIndex = (bufferTailIndex + 1) % sizeOfTheBuffer;
				elementsInBuffer--;

				if (bufferTailIndex == 0)
					return (buffer[sizeOfTheBuffer - 1]);
				else
					return (buffer[(bufferTailIndex - 1) % sizeOfTheBuffer]);
			}
		}
		catch ( int emptyBufferException) {
			std::cout << "ERROR OCCURED! YOU HAVE TRIED TO TAKE AN ELEMENT FORM EMPTY BUFFER. ERROR NUMBER: " << emptyBufferException << std::endl;
			exit(-1);
		}
	
	}

	bufferSizeDatatype getNumberOfElementsInTheBuffer() {
		return elementsInBuffer;
	}

	bufferSizeDatatype getBufferSize() {
		return sizeOfTheBuffer;
	}

	bufferSizeDatatype getBufferEmptySpotsLeft() {
		return (sizeOfTheBuffer - elementsInBuffer);
	}


};