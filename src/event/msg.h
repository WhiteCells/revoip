#pragma once

#include <string>
#include <chrono>

struct Msg
{
    Msg()
    {
    }

    virtual ~Msg() = 0;
};

// 接收到的 ASR 消息
// 用于通知 LLM 有新的 ASR 文本需要回复
struct ASRTextMsg : public Msg
{
    explicit ASRTextMsg(const std::string &text)
        : m_text(text)
    {
    }

    std::string m_text;
};

// 接收到的 ASR 打断消息
struct ASRStopMsg : public Msg
{
    explicit ASRStopMsg()
    {
    }
};

// 接收到的 LLM 消息
// 用于通知 TTS 有新的 LLM 文本的音频需要生成
struct LLMTextMsg : public Msg
{
    explicit LLMTextMsg(const std::string &text)
        : m_text(text)
    {
    }

    std::string m_text;
};