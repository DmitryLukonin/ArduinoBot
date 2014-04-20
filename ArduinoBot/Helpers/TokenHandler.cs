using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;
using System.Web;

namespace ArduinoBot.Helpers
{
    public class TokenHandler : DelegatingHandler
    {
        private HttpRequestMessage _request;

        protected override Task<HttpResponseMessage> SendAsync(HttpRequestMessage request, CancellationToken cancellationToken)
        {
            _request = request;

            request.Properties[SessionHelper.BotAuthHeader] = GetHeaderValue(SessionHelper.BotAuthHeader);
            request.Properties[SessionHelper.CoreAuthHeader] = GetHeaderValue(SessionHelper.CoreAuthHeader);


            return base.SendAsync(request, cancellationToken);
        }

        private string GetHeaderValue(string headerName)
        {
            string key = null;

            key = _request.GetHeader(headerName);
            if (!string.IsNullOrWhiteSpace(key)) return key;

            key = MvcHelper.GetCookie(headerName);
            if (!string.IsNullOrWhiteSpace(key)) return key;

            key = MvcHelper.GetQueryString(headerName);
            if (!string.IsNullOrWhiteSpace(key)) return key;

            key = MvcHelper.GetForm(headerName);
            if (!string.IsNullOrWhiteSpace(key)) return key;

            return null;
        }

    }
}