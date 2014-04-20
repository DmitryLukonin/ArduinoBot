using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web;
using System.Web.Configuration;

namespace ArduinoBot.Helpers
{
    public class AuthorizeCoreCustomFilter : System.Web.Http.AuthorizeAttribute
    {
        public override void OnAuthorization(System.Web.Http.Controllers.HttpActionContext actionContext)
        {
            string token = null;
            try
            {
                token = Convert.ToString(actionContext.Request.Properties[SessionHelper.CoreAuthHeader]);
            }
            catch (Exception)
            {
                actionContext.Response = actionContext.Response = actionContext.Request.CreateResponse(HttpStatusCode.PartialContent);
                return;
            }


            if (string.IsNullOrWhiteSpace(token))
            {
                //actionContext.Response.ReasonPhrase = "Please provide valid inputs";
                actionContext.Response = actionContext.Request.CreateResponse(HttpStatusCode.NonAuthoritativeInformation);
                return;
            }

            if (!token.Equals(WebConfigurationManager.AppSettings["CoreAccessToken"]))
            {
                actionContext.Response = actionContext.Request.CreateResponse(HttpStatusCode.Forbidden);
                return;
            }

            //actionContext.Response = actionContext.Request.CreateResponse(HttpStatusCode.OK);
        }

    }
}