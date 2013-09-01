/*
 * TCProcessor.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "TCProcessor.h"
namespace Processors {
TCProcessor::TCProcessor() {
	_error = NO_ERROR;
}

void TCProcessor::init() {
	definitions_();
}

void TCProcessor::processRecv(String payload) {
	int sent_opcode = atoi(payload.substring(0, 2).c_str());
	/* Let's check that we can cast the sent opcode into a unit8. */
	if (sent_opcode > 256) {
		_error = INVALID_OPCODE;
		return;
	}
	uint8_t opcode = sent_opcode;
	/* Let's now parse the action. */
	uint8_t sent_action = atoi(payload.substring(2, 3).c_str());
	TC_ACTION action;
	switch (sent_action) {
	case 1:
		action = EXECUTE;
		break;
	case 3:
		action = ENABLE;
		break;
	case 5:
		action = DISABLE;
		break;
	default:
		_error = INVALID_ACTION;
		return;
	}
	perform(action, opcode);
}

void TCProcessor::perform(TC_ACTION action, uint8_t opcode) {
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

void TCProcessor::definitions_() {
	_opcode_TC_map[1] = new LogicTC(13, 0x1);
	_opcode_TC_map[2] = new LogicTC(13, 0x0);
}
}
