# Decorator to parse raw log string into a dictionary
def parse_log(func):
    def wrapper(logs, raw_log):
        try:
            arr = raw_log.split(" ", 3)
            timestamp = arr[0].strip("[]")
            level = arr[1]
            user = arr[2].strip(":")
            message = arr[3]

            log_dict = {
                "TimeStamp": timestamp,
                "level": level,
                "user": user,
                "message": message
            }

            return func(logs, log_dict)
        except Exception as e:
            print(f"Error parsing log: {e}")
            return logs
    return wrapper

# Function to add a parsed log dict to the logs list
@parse_log
def add_log(logs, parsed_log):
    logs.append(parsed_log)
    return logs

# Returns logs of a specific user
def get_user_logs(logs, user_id):
    return [log for log in logs if log["user"] == user_id]

# Counts the number of logs per level
def count_levels(logs):
    levels = {}
    for log in logs:
        lvl = log["level"]
        levels[lvl] = levels.get(lvl, 0) + 1
    return levels

# Filters logs containing a keyword
def filter_logs(logs, keyword):
    return [log for log in logs if keyword.lower() in log["message"].lower()]

# Gets the most recent N logs
def get_recent_logs(logs, n=2):
    return logs[-n:] if len(logs) >= n else logs

# Main driver
if __name__ == "__main__":
    logs = []

    # Sample input (simulate user input)
    raw_log_1 = "[2025-06-17 10:00:00] INFO user1:Started the service"
    raw_log_2 = "[2025-06-17 10:05:00] ERROR user2:Service failed"
    raw_log_3 = "[2025-06-17 10:10:00] INFO user1:Service restarted"

    logs = add_log(logs, raw_log_1)
    logs = add_log(logs, raw_log_2)
    logs = add_log(logs, raw_log_3)

    print("All Logs:")
    for log in logs:
        print(log)

    print("\nLogs for user1:")
    print(get_user_logs(logs, "user1"))

    print("\nLog Levels Count:")
    print(count_levels(logs))

    print("\nLogs containing 'failed':")
    print(filter_logs(logs, "failed"))

    print("\nMost Recent Log:")
    print(get_recent_logs(logs, 1))
