#!/usr/bin/env ruby

require 'net/http'

params = [ "aaa=111",
           "bbb=222",
           "ccc=333",
           "ddd=444",
           "eee=555",
           "fff=666",
           "ggg=777",
           "hhh=888",
           "iii=999"]

def create_url(url_params)
  req_url = "/test?"
  url_params.shuffle.each do |param|
    req_url << param << "&"
  end
  return req_url
end

threads = []

(0..9).each do |x|
  threads << Thread.new(create_url(params.shuffle)) { |shuffled_params|
     h = Net::HTTP.new("localhost", 80)
     (0..999).each do |i|
          resp, data = h.get(shuffled_params, nil)
 #         puts "GET http://localhost#{shuffled_params}"
     end
  }
end

threads.each { |aThread|  aThread.join }

