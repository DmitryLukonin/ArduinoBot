using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Mvc;
using ArduinoBot.Helpers;
using ArduinoBot.Models;

namespace ArduinoBot.Controllers
{
    public class CommandController : ApiController
    {
        [System.Web.Http.HttpGet]
        //[AuthorizeBotCustomFilter]
        public HttpResponseMessage Get()
        {
            var command = SessionHelper.CommandReadNext();
            return Request.CreateResponse(HttpStatusCode.OK, command);
        }

        [System.Web.Http.HttpGet]
        public HttpResponseMessage GetAllCommands()
        {
            var response = SessionHelper.Commands();
            return Request.CreateResponse(HttpStatusCode.OK, response);
        }

        [System.Web.Http.HttpGet]
        public HttpResponseMessage GetAllCommands(long id)
        {
            var command = SessionHelper.Commands().Where(x => x.Id > id);
            return Request.CreateResponse(HttpStatusCode.OK, command);
        }

        //[AuthorizeCoreCustomFilter]
        public void Post(Command command)
        {
            SessionHelper.CommandAdd(command);
        }
    }
}