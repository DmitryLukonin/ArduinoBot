using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Helpers;
using System.Web.Http;
using ArduinoBot.Helpers;
using ArduinoBot.Models;

namespace ArduinoBot.Controllers
{
    public class ResponseController : ApiController
    {
        [HttpGet]
        //[AuthorizeCoreCustomFilter]
        public HttpResponseMessage Get()
        {
            var response = SessionHelper.ResponseReadNext();
            return Request.CreateResponse(HttpStatusCode.OK, response);
        }

        [HttpGet]
        public HttpResponseMessage GetAllResponses()
        {
            var response = SessionHelper.Responses();
            return Request.CreateResponse(HttpStatusCode.OK, response);
        }

        [HttpGet]
        public HttpResponseMessage GetAllResponses(long id)
        {
            var response = SessionHelper.Responses().Where(x => x.Id > id);
            return Request.CreateResponse(HttpStatusCode.OK, response);
        }

        [HttpPost]
        //[AuthorizeBotCustomFilter]
        public void Post(ResponseFromBot text)
        {
            var item = new Response() { Text = text.Text };
            SessionHelper.ResponseAdd(item);
        }
    }
}