/*
 * TCProcessor.h
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#ifndef TCPROCESSOR_H_
#define TCPROCESSOR_H_

#include "TC.h"
#include "DigitalWriteTC.h"
/* The following includes enable STL for Arduino. */
#include <iterator>
#include <map>
/**
 * @class TCProcessor manages all the telecommands in a std::map . It is also called by GlobalReceiver upon receiving commanding instruction.
 */
class TCProcessor {
public:
	/**
	 * @brief The constructor only initializes private attributes of this class.
	 */
	TCProcessor();
	/**
	 * @brief The init function will call 'init' on all the telecommands of this class.
	 * This function must be called from the setup function in the main.
	 */
	void init();

	/**
	 * @enum TC_ACTION Defines different actions available for commands.
	 */
	enum TC_ACTION {
		EXECUTE, /**< this executes the given TC */
		ENABLE, /**< this enables the given TC */
		DISABLE/**< this disables the given TC */
	};

	/**
	 * @enum ERROR_STATE defines all the error states the TC Processor can report.
	 */
	enum ERROR_STATE {
		NO_ERROR, /**< nominal state */
		INVALID_OPCODE, /**< if attempting to perform an action on an invalid OPCODE */
		INVALID_ACTION /**< if attempting to perform an action which is not defined */
	};

	/**
	 * @brief This function processes the input string which contains the OPCODE to concerned along with the action to take.
	 * This function will set the internal error variable accordingly, if there is an error of course.
	 * This function calls the @ref process function which manages command execution, enabling, disabling, etc.
	 * @param payload input passed on by the GlobalReceiver in order to process the desired command.
	 */
	void processRecv(String payload);

	/**
	 * @brief This function will perform the given action on the given opcode.
	 * The internal error variable will reflect whether the OPCODE is valid. Due to the limiting actions exposed by TC_ACTION,
	 * there is no need to check for the validity of the action.
	 * @param opcode
	 * @param action
	 */
	void perform(TC_ACTION action, int opcode);

	virtual ~TCProcessor();
private:
	/**
	 * @brief The define_ function will define all the TCs available.
	 * It is called from the constructor and it populates the map.
	 * This is where the correspondence between the OPCODE and the given TC is done. Note that this also where the Start of Service tool
	 * output should be place (for TC generation).
	 */
	void define_();
	/**
	 * @brief This is the correspondence list between OPCODE and TC object. Here will be fetched and added all the TCs.
	 */
	std::map<int, TC*> _opcode_TC_map;

	ERROR_STATE _error;

};

#endif /* TCPROCESSOR_H_ */
