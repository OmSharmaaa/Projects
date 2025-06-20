# -*- coding: utf-8 -*-
"""Logging System.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/176XcqbVdvJxo4nB5-UiN3MZM58EasoI4
"""

def add_log(logs):
    s = input("Enter log (format: yyyy-mm-dd HH:MM:SS:Level:UserID:Message): ").split(':')

    if len(s) < 5:
        print("Invalid log format.")
        return logs

    time = ':'.join(s[:3])
    level = s[3]
    user_id = int(s[4])
    message = ':'.join(s[5:])

    log = {
        'time': time,
        'level': level,
        'user_id': user_id,
        'message': message
    }
    logs.append(log)
    return logs

def get_user_logs(logs, user_id):
    user_logs = []
    for log in logs:
        if log['user_id'] == user_id:
            user_logs.append(log)
    return user_logs

def count_levels(logs):
    levels = {}
    for log in logs:
        level = log['level']
        levels[level] = levels.get(level, 0) + 1
    return levels

def filter_logs(logs, keyword):
    keyword_logs = []
    for log in logs:
        if keyword.lower() in log['message'].lower():
            keyword_logs.append(log)
    return keyword_logs

def get_recent_logs(logs, n=2):
    return logs[-n:] if len(logs) >= n else logs

if __name__ == '__main__':
    logs = []
    logs = add_log(logs)

    user_logs = get_user_logs(logs, 1)
    print(user_logs)

    count = count_levels(logs)
    print(count)

    filtered = filter_logs(logs, "Start")
    print(filtered)

    recent_cap = get_recent_logs(logs, 1)
    print(recent_cap)