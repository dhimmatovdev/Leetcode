#!/bin/bash

# Telegram API tokeni va chat ID
TELEGRAM_TOKEN="7810021985:AAHdwZgCgBSB8Y_ADh-5LFz8dYd4ptgWF3U"
CHAT_ID="1849552036"  # To'g'ri chat ID

# Xabar matnini argumentdan olish
MESSAGE="$1"

# Xabar matnining bo'sh emasligini tekshirish
if [ -z "$MESSAGE" ]; then
  echo "Error: Message is empty"
  exit 1
fi

# Xabarni Telegram API orqali yuborish
curl -s -X POST "https://api.telegram.org/bot$TELEGRAM_TOKEN/sendMessage" \
    -d chat_id=$CHAT_ID \
    -d text="$MESSAGE"

# Statusni tekshirish
if [ $? -eq 0 ]; then
  echo "Message sent successfully!"
else
  echo "Failed to send message"
fi
