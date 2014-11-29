/**
 *             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                     Version 2, December 2004
 *
 * Copyright (C) 2014 Daniel Hrabovcak
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
**/
#ifndef FROM_FUNCTION_PTR_HPP_fa3022b9677c0e1494c23a36f0d43b82
#define FROM_FUNCTION_PTR_HPP_fa3022b9677c0e1494c23a36f0d43b82

/*!
 * @brief  Sets a function pointer definition.
 * @tparam RetrunType The return type for the function definition.
 * @tparam Args The argument list for the function definition.
 */
template <typename ReturnType, typename... Args>
class from_function_ptr
{
public:

	/*!
	 * @brief  The function pointer definition.
	 */
	typedef ReturnType (*type)(Args...);

	/*!
	 * @brief  A functor that converts a given function definition to another.
	 * @tparam Function The pointer to the function to convert.
	 * @tparam ExtendedArgs The new arguments to add to the given function.
	 */
	template <type Function, typename... ExtendedArgs> class with
	{
	public:

		/*!
		 * @brief  The converted function pointer definition.
		 */
		typedef ReturnType (*type)(Args... args, ExtendedArgs... ext);

		/*!
		 * @brief  Executes the converted function. All extended arguments are
		 *         unused and ignored.
		 */
		inline static ReturnType function(Args... args, ExtendedArgs...)
		{
			return Function(args...);
		}

		/*!
		 * @brief  Executes the converted function, ignoring the returned value.
		 *         All extended arguments are unused and ignored.
		 */
		inline static void void_function(Args... args, ExtendedArgs...)
		{
			Function(args...);
		}
	};
};

#endif // FROM_FUNCTION_PTR_HPP_fa3022b9677c0e1494c23a36f0d43b82