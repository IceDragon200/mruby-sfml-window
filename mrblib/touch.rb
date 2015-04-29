module SFML
  module Touch
    class << self
      alias :down? :is_down
      alias :position :get_position
    end
  end
end
