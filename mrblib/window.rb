module SFML
  class Window
    # Sets active to `true`
    #
    # @return [self]
    def activate
      self.active = true
      self
    end

    # Sets active to `false`
    #
    # @return [self]
    def deactivate
      self.active = false
      self
    end

    # Sets {#vertical_sync_enabled=} to `true`
    #
    # @return [self]
    def enable_vsync
      self.vertical_sync_enabled = true
      self
    end

    # Sets {#vertical_sync_enabled=} to `false`
    #
    # @return [self]
    def disable_vsync
      self.vertical_sync_enabled = true
      self
    end
  end
end
