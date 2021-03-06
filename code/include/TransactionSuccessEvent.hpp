#if !defined TRANSACTION_SUCCESS_EVENT_HPP
#define TRANSACTION_SUCCESS_EVENT_HPP

#include "EventInterface.hpp"
#include "EventType.hpp"
#include "ActorId.hpp"

/* TransactionSuccessEvent represents the event where a transaction is checked.
 *  Contains information on ship and port involved. */
class TransactionSuccessEvent : public EventInterface
{
public:

  TransactionSuccessEvent();

  TransactionSuccessEvent(ActorId ship_id,
			  ActorId port_id,
			  unsigned int ship_gold,
			  unsigned int ship_rum,
			  unsigned int port_rum);

  virtual ~TransactionSuccessEvent();

  virtual EventType getEventType() const;

  /* Ship ID setter */
  void setShipId(ActorId actor_id);

  /* Ship ID getter */
  ActorId getShipId() const;
  
  /* Port ID setter */
  void setPortId(ActorId actor_id);

  /* Port ID getter */
  ActorId getPortId() const;

  /* Ship gold setter */
  void setShipGold(unsigned int x);

  /* Ship gold getter */
  unsigned int getShipGold() const;

  /* Ship rum setter */
  void setShipRum(unsigned int y);

  /* Ship rum getter */
  unsigned int getShipRum() const;
  
  /* Port rum setter */
  void setPortRum(unsigned int y);

  /* Port rum getter */
  unsigned int getPortRum() const;

  /* TransactionSuccessEvent's event type */
  static const EventType event_type;

private:

  /* Actors associated with this event */
  ActorId ship_id, port_id;

  /* Rum and gold of actors associated with this event */
  unsigned int ship_gold;
  unsigned int ship_rum;
  unsigned int port_rum;
};

inline EventType TransactionSuccessEvent::getEventType() const
{
  return event_type;
}

inline void TransactionSuccessEvent::setShipId(ActorId actor_id)
{
  this->ship_id = actor_id;
}

inline ActorId TransactionSuccessEvent::getShipId() const
{
  return ship_id;
}

inline void TransactionSuccessEvent::setPortId(ActorId actor_id)
{
  this->port_id = actor_id;
}

inline ActorId TransactionSuccessEvent::getPortId() const
{
  return port_id;
}

inline void TransactionSuccessEvent::setShipGold(unsigned int x)
{
  this->ship_gold = x;
}

inline unsigned int TransactionSuccessEvent::getShipGold() const
{
  return ship_gold;
}

inline void TransactionSuccessEvent::setShipRum(unsigned int y)
{
  this->ship_rum = y;
}

inline unsigned int TransactionSuccessEvent::getShipRum() const
{
  return ship_rum;
}

inline void TransactionSuccessEvent::setPortRum(unsigned int y)
{
  this->port_rum= y;
}

inline unsigned int TransactionSuccessEvent::getPortRum() const
{
  return port_rum;
}


#endif
