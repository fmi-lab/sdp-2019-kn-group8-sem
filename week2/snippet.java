@Override
public List<ExtractedMetrics> extract(RecordContext context, InputStream recordStream) throws IOException, ParseException {

   InputContext recordContext = new InputContext(context.getBundle().getId(), context.getFilePath());
   List<Record> records = extractor.extract(recordStream, recordContext);
   log.info("Extracted {} records from payload {}. Time taken: {} msec.", records.size(), recordContext.getBundleId());
   List<ExtractedMetrics> extractedMetrics = new ArrayList<>();
   for (Iterator<Record> it = records.iterator(); it.hasNext(); ) {
      Record r = it.next();
      log.trace("converting record {} from {}", r, context);
      List<ExtractedMetrics> metricsFromRecord = dbModel.convertRecord(context, r);
		extractedMetrics.addAll(metricsFromRecord);
      it.remove();
   }

   extractedMetrics.addAll(dbModel.completeFile(context));
   log.info("Extraction phase finished. Extracted {} metrics. ", extractedMetrics.size());
   return extractedMetrics;
}