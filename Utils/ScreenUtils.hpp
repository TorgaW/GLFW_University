#ifndef D5BE0DB4_6F22_4B58_8AA9_8C4D27B7F958
#define D5BE0DB4_6F22_4B58_8AA9_8C4D27B7F958

class ScreenUtils
{
private:
    static inline int screen_size_w {0};
    static inline int screen_size_h {0};
public:
    static inline void SetScreenSize(int w, int h)
    {
        screen_size_w = w;
        screen_size_h = h;
    };
    static inline float GetWidth() { return screen_size_w; };
    static inline float GetHeight() { return screen_size_h; };
    ScreenUtils(){};
    ~ScreenUtils(){};
};


#endif /* D5BE0DB4_6F22_4B58_8AA9_8C4D27B7F958 */
