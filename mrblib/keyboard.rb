module SFML
  module Keyboard
    class << self
      alias :key_pressed? :is_key_pressed
      alias :virtual_keyboard_visible= :set_virtual_keyboard_visible
    end
  end
end
