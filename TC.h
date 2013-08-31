/*
 * TC.h
 *
 *  Created on: Aug 25, 2013
 *      Author: chris
 */

#ifndef TC_H_
#define TC_H_

/**
 * @brief This class defines a telecommand. It is high level and must be overwritten by low level classes.
 * In this class, high level functions are defined as non virtual. Lower level actions must be redefined
 * in subclasses. This allows consistency between each telecommand class.
 * A telecommand can be enabled or disable with the appropriate functions. Note that there is no toggle
 * function. This is to prevent double messages to be sent and enable then disable a command for example.
 */
class TC {
public:
	/**
	 * @brief This creates the TC object. The OPCODE of this TC is only defined in the main when the TC is instantiated.
	 */
	TC();
	virtual ~TC();
	/**
	 * @enum ERROR_STATE defines all the error states a TC can have.
	 */
	enum ERROR_STATE {
		NO_ERROR, /**< nominal state */
		NOT_ENABLED, /**< if attempting to start or stop when not enabled */
		WAS_ENABLED, /**< if attempting to enable and was already enabled */
		WAS_DISABLED, /**< if attempting to disable and was already disabled */
		WAS_NOT_PERSISTENT, /**< if attempting to clear the error and was not in persistent error mode */
	};
	/**
	 * @brief This function will enable this TC.
	 */
	void enable();
	/**
	 * @brief This function will disable this TC. A disabled TC cannot be executed.
	 */
	void disable();
	/**
	 * @brief This function will execute of this TC. A TC can only be executed (for start and stop actions, use procedures, embedded or not).
	 * This function will call __exec after shared features.
	 */
	void exec();

	/**
	 * @brief This function sets this TC to persist error (or not).
	 * @param persist set to true to make errors persistent. A persistent error will not reset the error state of this TC until commanded to do so.
	 */
	void persist_errors(bool persist);

	/**
	 * @brief This function will clear the current error. If called when persistent error are set to false, this will change the error state.
	 */
	void clear_error();

	/**
	 * @brief This function will return the current error of this TC.
	 * @note Once this function is called, the error state is returned to NO_ERROR unless if this TC is configured as having persistent error.
	 * @return The current error state.
	 */
	ERROR_STATE errno();
	/**
	 * @brief The init function sets up everything for this TC to be operational. It must be called from the setup function in the main.
	 * It must be implemented by the subclass.
	 */
	virtual void init() = 0;
	/**
	 * @brief This function will execute this TC.
	 */
	virtual void exec_impl_() = 0;
private:
	bool _enabled;
	bool _persistent_error;
	int _executions;
	ERROR_STATE _error;
};

#endif /* TC_H_ */
