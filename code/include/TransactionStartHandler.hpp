#if !defined TRANSACTION_START_HANDLER_HPP
#define TRANSACTION_START_HANDLER_HPP

#include <functional>

#include "EventDelegate.hpp"
#include "TransactionStartEvent.hpp"

/* Define an ActorMovedHandler as a function that takes an ActorMovedEvent and
 * returns nothing. */
typedef std::function<void(const TransactionStartEvent&)> TransactionStartHandler;

#endif