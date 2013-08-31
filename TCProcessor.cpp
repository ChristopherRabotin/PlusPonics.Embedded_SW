/*
 * TCProcessor.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "TCProcessor.h"

TCProcessor::TCProcessor() {
	_error = NO_ERROR;
}

void TCProcessor::init() {
	define_();
}

void TCProcessor::processRecv(String payload) {
}

void TCProcessor::perform(TC_ACTION action, int opcode) {
	if (_opcode_TC_map.find(opcode) == _opcode_TC_map.end()) {
		_error = INVALID_OPCODE;
		return;
	}
	TC* tc = _opcode_TC_map.find(opcode)->second;
	switch (action) {
	case ENABLE:
		tc->enable();
		break;
	case DISABLE:
		tc->disable();
		break;
	case EXECUTE:
		tc->exec();
		break;
	}
}

TCProcessor::~TCProcessor() {
}

void TCProcessor::define_() {
	_opcode_TC_map[1] = new DigitalWriteTC(13, 0x1);
}
