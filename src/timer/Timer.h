#pragma once

const int MAX_DELTATIME = 150.0f;

class Timer
{
    public:
        inline static Timer* GetInstance()
        {
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Timer();
        }

        void Tick();
        inline float GetDeltaTime()
        {
            return m_DeltaTime;
        }

    private:
        Timer() {};
        static Timer* s_Instance;

        float m_DeltaTime, m_LastTime;

};