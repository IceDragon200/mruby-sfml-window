module SFML
  module Joystick
    # @return [Hash<Symbol, Object>] identfication data
    def self.identification(id)
      data = identification_data(id)
      {
        name: data[0],
        vendor_id: data[1],
        product_id: data[2]
      }
    end
  end
end
