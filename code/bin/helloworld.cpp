#include <SFML/Graphics.hpp>

#define MAX_FRAME_RATE 60

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Hello World - SFML");

  // How fast is game time relative to real time?
  // 1 = game time is real time
  // (0 1) = game time is slower than real time
  // 0 = game time is paused
  // >1 = game time is faster than real time
  // <0 = game time runs in reverse
  double game_time_factor = 1.0;

  // Clocks for managing frame time.  'processing_clock' is used to determine
  // how long the processing required by the game takes, 'update_clock' is used
  // to determine how much time actually passes between successive game updates
  sf::Clock processing_clock;
  sf::Clock update_clock;

  // Update time for the first frame doesn't make sense because the update clock
  // is running before the game ever gets into the game loop, and because there
  // isn't a previous update from which to reference.  Instead of allowing
  // inconsistent behavior the update time for the first frame is forced to 0 to
  // force consistent first frame update behavior.  The rest of the frames
  // obviously don't do this.
  bool first_frame = true;


  // start main loop
  while(App.isOpen())
  {
    // We're at the beginning of the frame, so we want to start tracking how
    // long we take to do game processing now.
    processing_clock.restart();


    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }


    // How much time has passed since the last update?
    sf::Time update_time = update_clock.restart();
    if (first_frame)
    {
      // Force a no-op update on the first frame
      update_time = sf::seconds(0.0);
    }


    // UPDATE HERE, pass in update_time * game_time_factor


    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    // display
    App.display();


    // How much time did this frame's processing take?
    sf::Time processing_time = processing_clock.getElapsedTime();

    // Cap the frame rate at MAX_FRAME_RATE
    if (processing_time.asSeconds() < 1.0 / MAX_FRAME_RATE)
    {
      // Construct a time representing how much time we need to sleep
      sf::Time sleep_time =
	sf::seconds((1.0 / MAX_FRAME_RATE) - processing_time.asSeconds());

      sf::sleep(sleep_time);
    }


    // It's about to not be the first frame anymore so make that note
    first_frame = false;
  }

  // Done.
  return 0;
}
