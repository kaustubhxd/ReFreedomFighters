// TEX (texture) parser and pixel decoders for Freedom Fighters. Pure module: no DOM, no WebGL.
// Layout and evidence: formats/tex-format.md; reference decoder: decoders/tex.py.

function fourCC(view, offset) {
  return String.fromCharCode(...new Uint8Array(view.buffer, view.byteOffset + offset, 4));
}

function readCString(bytes, offset, limit) {
  let end = offset;
  while (end < limit && bytes[end] !== 0) end += 1;
  if (end === limit) throw new Error("Unterminated texture name.");
  return { value: new TextDecoder("latin1").decode(bytes.subarray(offset, end)), next: end + 1 };
}

const TEX_LOOKUP_SLOTS = 2048;
const TEX_RECORD_FORMATS = new Set(["1TXD", "3TXD", "ABGR", "NLAP"]);
// NLAP (PAL8, UI art) is decoded (tex-format.md section 9.3).
const RENDERABLE_TEXTURE_FORMATS = new Set(["1TXD", "3TXD", "ABGR", "NLAP"]);

function isRenderableTexture(texture) {
  return Boolean(texture && RENDERABLE_TEXTURE_FORMATS.has(texture.format));
}

function parseTex(buffer) {
  if (buffer.byteLength < 16) throw new Error("File is too small to be a TEX resource.");
  const view = new DataView(buffer);
  const bytes = new Uint8Array(buffer);
  const contentEnd = view.getUint32(0, true);
  const lookupEnd = view.getUint32(4, true);
  if (contentEnd <= 16 || contentEnd > buffer.byteLength) throw new Error("Invalid TEX content boundary.");
  if (lookupEnd < contentEnd || lookupEnd > buffer.byteLength) throw new Error("Invalid TEX lookup-table boundary.");
  if (lookupEnd - contentEnd < TEX_LOOKUP_SLOTS * 4) throw new Error("TEX lookup table is shorter than 2,048 entries.");
  const records = [];
  const recordsByOffset = new Map();
  const recordsById = new Map();
  // Header +4 is LUT2 (animation-table offsets per texId). Its targets sit
  // inline in the content area (C05A has one), so skip them explicitly while
  // walking (tex-format.md sections 1 and 9.4).
  const animationTables = new Set();
  if (buffer.byteLength - lookupEnd >= TEX_LOOKUP_SLOTS * 4) {
    for (let index = 0; index < TEX_LOOKUP_SLOTS; index += 1) {
      const tableOffset = view.getUint32(lookupEnd + index * 4, true);
      if (tableOffset >= 16 && tableOffset < contentEnd) animationTables.add(tableOffset);
    }
  }
  let offset = 16;
  while (offset < contentEnd) {
    if (animationTables.has(offset)) {
      offset += 4 + view.getUint32(offset, true) * 4;
      continue;
    }
    if (offset + 36 > contentEnd) throw new Error(`Truncated TEX data at 0x${offset.toString(16)}.`);
    const format = fourCC(view, offset + 4);
    if (!TEX_RECORD_FORMATS.has(format)) {
      // Some archives put an animation record-ID table directly after a run
      // of texture frames. It has no FourCC, so distinguish it from a corrupt
      // texture record by requiring every referenced ID to be already known.
      const animationCount = view.getUint32(offset, true);
      const animationEnd = offset + 4 + animationCount * 4;
      const hasKnownAnimationIds = animationCount > 0
        && animationEnd <= contentEnd
        && Array.from({ length: animationCount }, (_, index) => view.getUint32(offset + 4 + index * 4, true))
          .every((id) => recordsById.has(id));
      if (hasKnownAnimationIds) {
        offset = animationEnd;
        continue;
      }
      throw new Error(`Unknown TEX record format at 0x${offset.toString(16)}.`);
    }
    const entrySize = view.getUint32(offset, true);
    // `entrySize` spans the complete record, including the 16-byte leading
    // header.  The next entry follows immediately at offset + entrySize.
    const recordEnd = offset + entrySize;
    if (entrySize < 36 || recordEnd > contentEnd) throw new Error(`Invalid TEX entry at 0x${offset.toString(16)}.`);
    const format2 = fourCC(view, offset + 8);
    if (format2 !== format) throw new Error(`Mismatched TEX format fields at 0x${offset.toString(16)}.`);
    const id = view.getUint32(offset + 12, true);
    const height = view.getUint16(offset + 16, true);
    const width = view.getUint16(offset + 18, true);
    const imageCount = view.getUint32(offset + 20, true);
    if (imageCount > 64) throw new Error(`TEX image count is unsafe at 0x${offset.toString(16)}.`);
    const flags = view.getUint32(offset + 24, true);
    const nameInfo = readCString(bytes, offset + 36, recordEnd);
    let cursor = nameInfo.next;
    const images = [];
    for (let index = 0; index < imageCount; index += 1) {
      if (cursor + 4 > recordEnd) throw new Error(`Truncated image list in ${nameInfo.value}.`);
      const size = view.getUint32(cursor, true);
      cursor += 4;
      if (cursor + size > recordEnd) throw new Error(`Truncated image data in ${nameInfo.value}.`);
      images.push({ offset: cursor, size });
      cursor += size;
    }
    let palette = null;
    if (format === "NLAP") {
      if (cursor + 4 > recordEnd) throw new Error(`Truncated palette in ${nameInfo.value}.`);
      const paletteCount = view.getUint32(cursor, true);
      cursor += 4;
      if (paletteCount > 256 || cursor + paletteCount * 4 !== recordEnd) throw new Error(`Invalid palette in ${nameInfo.value}.`);
      palette = { offset: cursor, count: paletteCount };
    } else if (cursor !== recordEnd) {
      throw new Error(`Unexpected trailing TEX data in ${nameInfo.value}.`);
    }
    const record = { offset, name: nameInfo.value, id, width, height, flags, format, format2, image: images[0], images, palette, buffer };
    records.push(record);
    recordsByOffset.set(offset, record);
    recordsById.set(id, record);
    offset = recordEnd;
  }
  const lookup = new Array(TEX_LOOKUP_SLOTS).fill(null);
  for (let index = 0; index < TEX_LOOKUP_SLOTS; index += 1) {
    const recordOffset = view.getUint32(contentEnd + index * 4, true);
    if (!recordOffset) continue;
    const record = recordsByOffset.get(recordOffset);
    if (!record) throw new Error(`TEX lookup #${index} points outside its record table.`);
    lookup[index] = record;
  }
  return { records, recordsById, lookup };
}

function resolveMaterialTexture(textureCatalog, rawMaterialId) {
  if (!textureCatalog) return null;
  const lookupIndex = rawMaterialId & 0x7ff;
  return textureCatalog.lookup[lookupIndex] || textureCatalog.recordsById.get(rawMaterialId) || null;
}

function decode565(value) {
  return [
    Math.round(((value >>> 11) & 31) * 255 / 31),
    Math.round(((value >>> 5) & 63) * 255 / 63),
    Math.round((value & 31) * 255 / 31),
  ];
}

function mix(a, b, aWeight, bWeight) {
  return [
    Math.round((a[0] * aWeight + b[0] * bWeight) / (aWeight + bWeight)),
    Math.round((a[1] * aWeight + b[1] * bWeight) / (aWeight + bWeight)),
    Math.round((a[2] * aWeight + b[2] * bWeight) / (aWeight + bWeight)),
    255,
  ];
}

function dxtColorPalette(view, offset, order, forceFourColor) {
  const colorLittleEndian = order === "little";
  const color0 = view.getUint16(offset, colorLittleEndian);
  const color1 = view.getUint16(offset + 2, colorLittleEndian);
  const first = [...decode565(color0), 255];
  const second = [...decode565(color1), 255];
  const palette = [first, second];
  if (forceFourColor || color0 > color1) {
    palette.push(mix(first, second, 2, 1), mix(first, second, 1, 2));
  } else {
    palette.push(mix(first, second, 1, 1), [0, 0, 0, 0]);
  }
  return palette;
}

function decodeDxt1Pixels(texture, order = "little") {
  const { buffer, image, width, height } = texture;
  const expectedSize = Math.ceil(width / 4) * Math.ceil(height / 4) * 8;
  if (image.size < expectedSize) throw new Error(`DXT1 payload is ${expectedSize - image.size} bytes short.`);
  const view = new DataView(buffer, image.offset, image.size);
  const pixels = new Uint8Array(width * height * 4);
  const indicesLittleEndian = order !== "all-big";
  let byteOffset = 0;
  for (let blockY = 0; blockY < Math.ceil(height / 4); blockY += 1) {
    for (let blockX = 0; blockX < Math.ceil(width / 4); blockX += 1) {
      const indices = view.getUint32(byteOffset + 4, indicesLittleEndian);
      const palette = dxtColorPalette(view, byteOffset, order, false);
      byteOffset += 8;
      for (let pixel = 0; pixel < 16; pixel += 1) {
        const x = blockX * 4 + (pixel & 3);
        const y = blockY * 4 + (pixel >>> 2);
        if (x >= width || y >= height) continue;
        const color = palette[(indices >>> (pixel * 2)) & 3];
        const destination = (y * width + x) * 4;
        pixels[destination] = color[0];
        pixels[destination + 1] = color[1];
        pixels[destination + 2] = color[2];
        pixels[destination + 3] = color[3];
      }
    }
  }
  return pixels;
}

function decodeDxt3Pixels(texture, order = "little") {
  const { buffer, image, width, height } = texture;
  const expectedSize = Math.ceil(width / 4) * Math.ceil(height / 4) * 16;
  if (image.size < expectedSize) throw new Error(`DXT3 payload is ${expectedSize - image.size} bytes short.`);
  const view = new DataView(buffer, image.offset, image.size);
  const pixels = new Uint8Array(width * height * 4);
  const indicesLittleEndian = order !== "all-big";
  let byteOffset = 0;
  for (let blockY = 0; blockY < Math.ceil(height / 4); blockY += 1) {
    for (let blockX = 0; blockX < Math.ceil(width / 4); blockX += 1) {
      const palette = dxtColorPalette(view, byteOffset + 8, order, true);
      const indices = view.getUint32(byteOffset + 12, indicesLittleEndian);
      for (let pixel = 0; pixel < 16; pixel += 1) {
        const x = blockX * 4 + (pixel & 3);
        const y = blockY * 4 + (pixel >>> 2);
        if (x >= width || y >= height) continue;
        const alphaWord = view.getUint16(byteOffset + (pixel >>> 2) * 2, true);
        const alpha = ((alphaWord >>> ((pixel & 3) * 4)) & 0x0f) * 17;
        const color = palette[(indices >>> (pixel * 2)) & 3];
        const destination = (y * width + x) * 4;
        pixels[destination] = color[0];
        pixels[destination + 1] = color[1];
        pixels[destination + 2] = color[2];
        pixels[destination + 3] = alpha;
      }
      byteOffset += 16;
    }
  }
  return pixels;
}

function decodeAbgrPixels(texture) {
  const { buffer, image, width, height } = texture;
  const expectedSize = width * height * 4;
  if (image.size < expectedSize) throw new Error(`ABGR payload is ${expectedSize - image.size} bytes short.`);
  // Verified against the installed C01A resources and the format reference:
  // the payload is passed through as straight RGBA bytes despite its historic
  // ABGR FourCC name. Keep alpha unpremultiplied for WebGL.
  return new Uint8Array(buffer, image.offset, expectedSize).slice();
}

function decodeNlapPixels(texture) {
  // PAL8: w*h index bytes at mip 0, then u32 count + RGBA palette entries
  // (tex-format.md section 2 and 9.3). Out-of-range indices become transparent.
  const { buffer, image, width, height, palette } = texture;
  if (!palette) throw new Error("NLAP texture has no palette.");
  if (image.size < width * height) throw new Error(`NLAP payload is ${width * height - image.size} bytes short.`);
  const indices = new Uint8Array(buffer, image.offset, width * height);
  const colors = new Uint8Array(buffer, palette.offset, palette.count * 4);
  const pixels = new Uint8Array(width * height * 4);
  for (let pixel = 0; pixel < indices.length; pixel += 1) {
    const index = indices[pixel];
    if (index < palette.count) pixels.set(colors.subarray(index * 4, index * 4 + 4), pixel * 4);
  }
  return pixels;
}

function decodeTexturePixels(texture, order = "little") {
  if (!isRenderableTexture(texture) || !texture.image) throw new Error(`Unsupported texture format ${texture?.format || "unknown"}.`);
  if (texture.format === "1TXD") return decodeDxt1Pixels(texture, order);
  if (texture.format === "3TXD") return decodeDxt3Pixels(texture, order);
  if (texture.format === "NLAP") return decodeNlapPixels(texture);
  return decodeAbgrPixels(texture);
}

/** All stored mip levels as {width, height, pixels}; each level halves (floor, min 1). */
function decodeTextureLevels(texture) {
  const levels = [];
  let width = texture.width;
  let height = texture.height;
  // PAL8 indices exist only for the base level (every sample NLAP is single-level).
  const images = texture.format === "NLAP" ? texture.images.slice(0, 1) : texture.images;
  for (const image of images) {
    levels.push({ width, height, pixels: decodeTexturePixels({ ...texture, image, width, height }, "little") });
    if (width === 1 && height === 1) break;
    width = Math.max(1, width >> 1);
    height = Math.max(1, height >> 1);
  }
  return levels;
}


export { fourCC, readCString, isRenderableTexture, parseTex, resolveMaterialTexture, decodeTexturePixels, decodeTextureLevels, TEX_LOOKUP_SLOTS };
