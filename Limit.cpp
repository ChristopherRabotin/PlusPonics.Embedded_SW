/*
 * Limit.cpp
 *
 *  Created on: Sep 1, 2013
 *      Author: chris
 */

#include "Limit.h"

namespace TM {

Limit::Limit() {
	_limit = 0;
	_opcode = 0;
	_type = NONE;

}

Limit::~Limit() {
}

void Limit::set_opcode(uint8_t opc) {
	_opcode = opc;
}

void Limit::set_limit(int32_t lim) {
	_limit = lim;
}

uint8_t Limit::check_limit(int32_t value) {
	switch (_type) {
	case NONE:
		return (0);
	case HIGH:
		return ((value < _limit) ? 0 : _opcode);
	case LOW:
		return ((value > _limit) ? 0 : _opcode);
	}
}

} /* namespace TM */
