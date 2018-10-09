#!/usr/bin/python3

"""
Creating a script to export data
"""


import json
import requests
from json import dump
from sys import argv


def to_jsonformat():
    """
    to_jsonformat - This script will export data to the json format

    userId: This is the user's id

    Return: standard output of who has completed their tasks

    """
    users = requests.get("https://jsonplaceholder.typicode.com/users/").json()
    to_do = requests.get("https://jsonplaceholder.typicode.com/todos/").json()

    with open("todo_all_employees.json", "w") as json_file:
        files = {}
        for users in users:
            lib = []
            files[users["id"]] = lib
            for task in to_do:
                if task["userId"] == users["id"]:
                    employee_info = {}
                    employee_info["username"] = users["username"]
                    employee_info["task"] = task["title"]
                    employee_info["completed"] = task["completed"]
                    lib.append(employee_info)
        json.dump(files, json_file)

if __name__ == "__main__":
    to_jsonformat()
