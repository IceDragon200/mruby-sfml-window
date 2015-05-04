module SFML
  # Window that serves as a target for OpenGL rendering
  class Window
    def initialize(*args)
    end

    # @param [VideoMode] video_mode
    # @param [String] title
    # @param [Style] style
    # @param [ContextSettings] settings
    def create(video_mode, title, style = Style::Default, settings = ContextSettings.new)
    end

    # @return [self]
    def close
    end

    # @return [Boolean]
    def is_open
    end

    # @return [ContextSettings]
    def get_settings
    end

    # @param [Event] event
    # @return [Boolean]
    def poll_event(event)
    end

    # @param [Event] event
    # @return [Boolean]
    def wait_event(event)
    end

    # @return [Vector2i]
    def get_position
    end

    # @param [Vector2i] pos
    # @return [self]
    def set_position(pos)
    end

    # @return [Vector2i]
    def get_size
    end

    # @param [Vector2i] size
    # @return [self]
    def set_size(size)
    end

    # @param [String] title
    # @return [self]
    def set_title(title)
    end

    # @param [Boolean] vis
    # @return [self]
    def set_visible(vis)
    end

    # @param [Boolean] enabled
    # @return [self]
    def set_vertical_sync_enabled(enabled)
    end

    # @param [Boolean] vis
    # @return [self]
    def set_mouse_cursor_visible(vis)
    end

    # @param [Boolean] enabled
    # @return [self]
    def set_key_repeat_enabled(enabled)
    end

    # @param [Integer] limit
    # @return [self]
    def set_framerate_limit(limit)
    end

    # @param [Float] thresh
    # @return [self]
    def set_joystick_threshold(thresh)
    end

    # @param [Boolean] active
    # @return [self]
    def set_active(active)
    end

    # @return [self]
    def request_focus
    end

    # @return [Boolean]
    def has_focus
    end

    # @return [self]
    def display
    end

    alias :open? :is_open
    alias :settings :get_settings
    alias :position :get_position
    alias :position= :set_position
    alias :size :get_size
    alias :size= :set_size
    alias :title= :set_title
    alias :visible= :set_visible
    alias :vertical_sync_enabled= :set_vertical_sync_enabled
    alias :mouse_cursor_visible= :set_mouse_cursor_visible
    alias :key_repeat_enabled= :set_key_repeat_enabled
    alias :framerate_limit= :set_framerate_limit
    alias :joystick_threshold= :set_joystick_threshold
    alias :active= :set_active
  end
end
