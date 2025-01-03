#!/bin/bash
TELEGRAM_TOKEN="7810021985:AAHdwZgCgBSB8Y_ADh-5LFz8dYd4ptgWF3U"
CHAT_ID="y1849552036" 
MESSAGE="$1"
curl -s -X POST "https://api.telegram.org/bot$TELEGRAM_TOKEN/sendMessage" \
    -d chat_id=$CHAT_ID \
    -d text="$MESSAGE"
