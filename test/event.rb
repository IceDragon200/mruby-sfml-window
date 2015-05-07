assert 'SFML::Event#type' do
  ev = SFML::Event.new
  assert_kind_of Integer, ev.type
  assert_kind_of SFML::Event::SizeEvent, ev.size
  assert_kind_of SFML::Event::KeyEvent, ev.key
  assert_kind_of SFML::Event::TextEvent, ev.text
  assert_kind_of SFML::Event::MouseMoveEvent, ev.mouse_move
  assert_kind_of SFML::Event::MouseButtonEvent, ev.mouse_button
  assert_kind_of SFML::Event::MouseWheelEvent, ev.mouse_wheel
  assert_kind_of SFML::Event::JoystickMoveEvent, ev.joystick_move
  assert_kind_of SFML::Event::JoystickButtonEvent, ev.joystick_button
  assert_kind_of SFML::Event::JoystickConnectEvent, ev.joystick_connect
  assert_kind_of SFML::Event::TouchEvent, ev.touch
  assert_kind_of SFML::Event::SensorEvent, ev.sensor
end
