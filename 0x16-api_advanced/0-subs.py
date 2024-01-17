#!/usr/bin/python3
"""
Queries the Reddit API and returns the number of subscribers for a given subreddit.
"""

import requests

def number_of_subscribers(subreddit):
    url = f"https://www.reddit.com/r/{subreddit}/about.json"
    headers = {"User-Agent": "my_bot/1.0"}  # Replace with your user agent

    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        data = response.json().get("data", {})

        if data:
            return data.get("subscribers", 0)
        else:
            return 0
    else:
        return 0

if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
        print("Please pass an argument for the subreddit to search.")
    else:
        print("{:d}".format(number_of_subscribers(sys.argv[1])))
