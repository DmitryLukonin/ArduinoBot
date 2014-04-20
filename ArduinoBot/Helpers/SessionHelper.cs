using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using ArduinoBot.Models;

namespace ArduinoBot.Helpers
{
    public static class SessionHelper
    {
        public static string BotAuthHeader = "BotKey";
        public static string CoreAuthHeader = "CoreKey";

        private static Object _commandLock = new Object();
        private static Object _responseLock = new Object();

        public static bool CommandAdd(Command command)
        {
            lock (_commandLock)
            {
                command.Id = GenerateNewCommandId();
                AppSession.Commands.Add(command);
                AppSession.CommandLastId = command.Id;
            }
            return true;
        }

        [HttpGet]
        public static Command CommandReadNext()
        {
            //var tagged = AppSession.Commands.Select((item, i) => new { Item = item, Index = (int?)i });
            //int? index = (from pair in tagged
            //    where pair.Item.Received == false
            //    select pair.Index).FirstOrDefault();

            Command command = AppSession.Commands.FirstOrDefault(x => x.Received == false);
            if (command != null)
            {
                command.Received = true;
                return command;
            }
            return null;
        }

        [HttpGet]
        public static List<Command> Commands()
        {
            return AppSession.Commands;
        }

        public static List<Command> CommandsUnread()
        {
            return AppSession.Commands.Where(x => x.Received == false).ToList();
        }

        public static bool ResponseAdd(Response response)
        {
            lock (_responseLock)
            {
                response.Id = GenerateNewResponseId();
                AppSession.Responses.Add(response);
                AppSession.ResponseLastId = response.Id;
            }
            return true;
        }

        public static Response ResponseReadNext()
        {
            Response response = AppSession.Responses.FirstOrDefault(x => x.Received == false);
            if (response != null)
            {
                response.Received = true;
                return response;
            }
            return null;
        }

        public static List<Response> Responses()
        {
            return AppSession.Responses;
        }


        private static long GenerateNewCommandId()
        {
            var id = AppSession.CommandLastId;
            if (id == 0) id = GenerateNewId();

            id++;
            return (id);
        }
        private static long GenerateNewResponseId()
        {
            var id = AppSession.ResponseLastId;
            if (id == 0) id = GenerateNewId();

            id++;
            return (id);
        }
        private static int GenerateNewId()
        {
            var date = DateTime.UtcNow.Day.ToString() + DateTime.UtcNow.Hour.ToString() +
                       DateTime.UtcNow.Minute.ToString() + DateTime.UtcNow.Second.ToString();
            return int.Parse(date);
        }

    }
}