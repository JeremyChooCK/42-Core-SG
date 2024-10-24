import time, datetime

first_time = datetime.datetime(1970, 1, 1)
current_dateTime = datetime.datetime.now()

# print(first_time)
# print(current_dateTime)

difference = current_dateTime - first_time
hours_in_seconds = difference.total_seconds()

# print("test", hours_in_seconds )

print("Seconds since January 1, 1970:", f'{hours_in_seconds:,}', "or", "{:e}".format(hours_in_seconds))
month = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
print(month[current_dateTime.month], current_dateTime.day, current_dateTime.year)